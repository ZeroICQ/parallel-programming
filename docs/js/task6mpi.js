var a10in8element = document.getElementById("10in8");
var a10in8 = new Chart(a10in8element, {
    type: "horizontalBar",
    options: {
        title: {
            display: true,
            text: "10^8",
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
        labels: ["1 processes", "2 processes", "3 processes", "4 processes",
                 "5 processes", "6 processes", "7 processes", "8 processes"],
         datasets: [{
            label:"время",
            data: [
                1.10689,
                0.568174,
                0.375545,
                0.277374,
                0.860233,
                0.187553,
                0.242616,
                0.423264,
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

var a10in7element = document.getElementById("10in7");
var a10in7 = new Chart(a10in7element, {
    type: "horizontalBar",
    options: {
        title: {
            display: true,
            text: "10^7",
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
        labels: ["1 processes", "2 processes", "3 processes", "4 processes",
                 "5 processes", "6 processes", "7 processes", "8 processes"],
         datasets: [{
            label:"время",
            data: [
                0.110875,
                0.0569864,
                0.0377725,
                0.037279,
                0.0225551,
                0.0357189,
                0.0175638,
                0.0270417
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