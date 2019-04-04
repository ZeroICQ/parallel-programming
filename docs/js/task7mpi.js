var timeelement = document.getElementById("time");
var time = new Chart(timeelement, {
    type: "horizontalBar",
    options: {
        title: {
            display: true,  
            text: "elapsed tme",
        },
        legend: {
            display: false,
        },
        scales: {
            xAxes: [{
                ticks: {
                    beginAtZero:true
                },
                scaleLabel: {
                    display: true,
                    labelString: 'время, сек'
                }
            }]
        }
    },

    data: {
        labels: ["800 MB", "400 MB", "200 MB", "100 MB", "50 MB"],
         datasets: [{
            label:"время",
            data: [
                14.2662,
                7.13493,
                3.5707,
                1.7869,
                0.8930
            ],
            backgroundColor: [
                'rgba(255, 99, 132, 0.2)',
                'rgba(54, 162, 235, 0.2)',
                'rgba(255, 206, 86, 0.2)',
                'rgba(75, 192, 192, 0.2)',
                'rgba(153, 102, 255, 0.2)',
                'rgba(255, 159, 64, 0.2)',
                'rgba(0, 120, 51, 0.2)',
                'rgba(255, 153, 255, 0.2)',
            ],
            borderColor: [
                'rgba(255,99,132,1)',
                'rgba(54, 162, 235, 1)',
                'rgba(255, 206, 86, 1)',
                'rgba(75, 192, 192, 1)',
                'rgba(153, 102, 255, 1)',
                'rgba(255, 159, 64, 1)',
                'rgba(0, 120, 51, 1)',
                'rgba(255, 153, 255, 1)',
            ],
            borderWidth: 1

         }]
    },

});


var bandwidthelement = document.getElementById("bandwidth");
var bandwidth = new Chart(bandwidthelement, {
    type: "horizontalBar",
    options: {
        title: {
            display: true,  
            text: "bandwidth",
        },
        legend: {
            display: false,
        },
        scales: {
            xAxes: [{
                ticks: {
                    beginAtZero:true
                },
                scaleLabel: {
                    display: true,
                    labelString: 'время, сек'
                }
            }]
        }
    },

    data: {
        labels: ["800 MB", "400 MB", "200 MB", "100 MB", "50 MB"],
         datasets: [{
            label:"время",
            data: [
                14.2662,
                7.13493,
                3.5707,
                1.7869,
                0.8930
            ],
            backgroundColor: [
                'rgba(255, 99, 132, 0.2)',
                'rgba(54, 162, 235, 0.2)',
                'rgba(255, 206, 86, 0.2)',
                'rgba(75, 192, 192, 0.2)',
                'rgba(153, 102, 255, 0.2)',
                'rgba(255, 159, 64, 0.2)',
                'rgba(0, 120, 51, 0.2)',
                'rgba(255, 153, 255, 0.2)',
            ],
            borderColor: [
                'rgba(255,99,132,1)',
                'rgba(54, 162, 235, 1)',
                'rgba(255, 206, 86, 1)',
                'rgba(75, 192, 192, 1)',
                'rgba(153, 102, 255, 1)',
                'rgba(255, 159, 64, 1)',
                'rgba(0, 120, 51, 1)',
                'rgba(255, 153, 255, 1)',
            ],
            borderWidth: 1

         }]
    },

});
