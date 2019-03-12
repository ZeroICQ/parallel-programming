import stat
import subprocess
import os
import sys
import tarfile
import paramiko
import getpass
from shutil import rmtree
import os.path as osp 



repo_directory = os.path.dirname(os.path.abspath(__file__))
tmp_repo_name = "tmp_repo"
archive_name = tmp_repo_name + ".tar.gz"


def eprint(*args):
    print(*args, file=sys.stderr)


# bug: python cannot delete readonly files on windows
def del_rw(action, name, exc):
    os.chmod(name, stat.S_IWRITE)
    # os.unlink(name)
    action(name)

def remove_readonly(fn, path, excinfo):
    try:
        os.chmod(path, stat.S_IWRITE)
        fn(path)
    except Exception as exc:
        print("Skipped:", path, "because:\n", exc)

    


def main():
    # clone local repository to get rid of unnecessary files
    try:
        cp = subprocess.run("git clone --depth=1 file://{repo_dir} {repo_name}".format(repo_name=tmp_repo_name,
                                                                                       repo_dir=repo_directory))
        if cp.returncode != 0:
            return

    except FileNotFoundError as fne:
        eprint(fne)
        eprint("Git was not found")
        return

    # make archive for faster upload
    try:
        with tarfile.open(archive_name, "x:gz") as f:
            f.add(tmp_repo_name)
    except FileExistsError as fne:
        eprint(fne)
        return

    # upload to cluster
    host = "cluster.dvfu.ru"
    port = 21
    username = "mogilevkin.ae"


    with paramiko.SSHClient() as ssh:
        ssh.set_missing_host_key_policy(paramiko.WarningPolicy())
        # password = getpass.getpass()
        ssh.connect(host, username=username, key_filename="cluster.ppk")

        with ssh.open_sftp() as sftp:
            sftp.put(archive_name, archive_name)

        remote_directory = "parallel-programming"

        cmds = []
        cmds.append("rm -rf {}".format(remote_directory))
        cmds.append("mkdir {}".format(remote_directory))
        # cmds.append("tar -zxf {} {} -C {}".format(archive_name, tmp_repo_name, remote_directory))
        cmds.append("tar -C {remote_dir} -zxf {archive_name} --strip=1".format(archive_name=archive_name, remote_dir=remote_directory))
        cmds.append("rm -f {}".format(archive_name))
        for cmd in cmds:
            #todo: print output
            stdin, stdout, stderr = ssh.exec_command(cmd)
            for e in stderr:
                print(e)


def remove_readlonly_attrubite(path):
    for root, dirs, files in os.walk(path):
        for fname in files:
            full_path = os.path.join(root, fname)
            os.chmod(full_path ,stat.S_IWRITE)

def remove_tree(dirname):
    """Remove whole directory tree
    Reimplemented in project explorer widget"""
    while osp.exists(dirname):
        try:
            rmtree(dirname, onerror=del_rw)
        except Exception as e:
            # This handles a Windows problem with shutil.rmtree.
            # See issue #8567.
            print(e)
            # if type(e).__name__ == "OSError":
            #     rmtree(error_path, ignore_errors=True)



if __name__ == "__main__":
    try:
        main()
    finally:
        # cleanup
        # remove readonly flag
        # remove_readlonly_attrubite(repo_directory + "/" + tmp_repo_name)
        # rmtree(repo_directory + "/" + tmp_repo_name, )
        remove_tree(repo_directory + "/" + tmp_repo_name)
        os.remove(archive_name)