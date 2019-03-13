var SpeedFromThreads05BillionElement = document.getElementById("SpeedFromThreads1Billion");

var SpeedFromThreads05Billion = new Chart(SpeedFromThreads05BillionElement, {
    type: "horizontalBar",
    options: {
        title: {
            display: true,
            text: "title",
        }
    },

    data: {
        labels: ["1 thread", "2 threads", "3 threads", "4 threads", 
                 "4 threads", "5 threads", "6 threads", "7 threads", "8 threads"],
         datasets: [{
            data: []
         }]
    }

});



var kekImg = new Image();
kekImg.src = "https://iknowyourmeme.files.wordpress.com/2016/04/14280761127830.jpg?w=616"
kekImg.onload = function() {
    var SpeedFromThreads1MillionElement = document.getElementById("SpeedFromThreads1Billion");
    var fillPattern = SpeedFromThreads1MillionElement.getContext("2d").createPattern(kekImg, 'repeat');

    var SpeedFromThreads1Billion = new Chart(SpeedFromThreads1MillionElement, {
        type: "horizontalBar",
        options: {
            title: {
                display: true,
                text: "5*10^8",
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
            labels: ["1 thread", "2 threads", "3 threads", "4 threads",
                     "5 threads", "6 threads", "7 threads", "8 threads"],
             datasets: [{
                label:"время",
                data: [
                    1.21454320009797812,
                    0.77193855098448694,
                    0.72178145195357502,
                    0.65427325305063277,
                    0.68989281693939120,
                    0.67565454507712275,
                    0.66334970609750599,
                    0.65097817103378475,

                ],
                backgroundColor: fillPattern,
                borderColor: 'rgba(255,99,132,1)',
                borderWidth: 1

             }]
        },

    });


};



var spongeBobImg = new Image();
spongeBobImg.src = "https://pixel.nymag.com/imgs/daily/selectall/2018/05/11/rainbow/imagination.w700.h700.jpg"
spongeBobImg.onload = function() {
    var SpeedFromThreads1MillionElement = document.getElementById("SpeedFromThreads1Million");
    var fillPattern = SpeedFromThreads1MillionElement.getContext("2d").createPattern(spongeBobImg, 'repeat');

    var SpeedFromThreads1Billion = new Chart(SpeedFromThreads1MillionElement, {
        type: "horizontalBar",
        options: {
            title: {
                display: true,
                text: "10^6",
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
            labels: ["1 thread", "2 threads", "3 threads", "4 threads",
                     "5 threads", "6 threads", "7 threads", "8 threads"],
             datasets: [{
                label:"время",
                data: [
                    0.00267730897758156,
                    0.00177013804204762,
                    0.00142262596637011,
                    0.00108176295179874,
                    0.00096493796445429,
                    0.00089244905393571,
                    0.00087713601533324,
                    0.00075812509749085
                ],
                backgroundColor: fillPattern,
                borderColor: 'rgba(255,99,132,1)',
                borderWidth: 1

             }]
        },

    });


}


var SpeedFromThreadsTenThousandsElement = document.getElementById("SpeedFromThreadsTenThousands");
var SpeedFromThreadsTenThousands = new Chart(SpeedFromThreadsTenThousandsElement, {
    type: "horizontalBar",
    options: {
        title: {
            display: true,
            text: "10^4",
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
        labels: ["1 thread", "2 threads", "3 threads", "4 threads",
                 "5 threads", "6 threads", "7 threads", "8 threads"],
         datasets: [{
            label:"время",
            data: [
                0.00006926804780960,
                0.00009703496471047,
                0.00007391790859401,
                0.00005905504804105,
                0.00005440204404294,
                0.00005444395355880,
                0.00004342908505350,
                0.00004507601261139
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


var size1el = document.getElementById("size1");
var size1 = new Chart(size1el, {
    type: "horizontalBar",
    options: {
        title: {
            display: true,
            text: "8 threads",
        },
        legend: {
            display: false,
        },
        scales: {
            xAxes: [{
                ticks: {
                    beginAtZero:false
                },
                scaleLabel: {
                    display: true,
                    labelString: 'время, сек'
                }
            }]
        }
    },

    data: {
        labels: ["10^8", "5*10^7", "2.5*10^7", "1.25*10^7"],
         datasets: [{
            label:"время",
            data: [
                0.13104884896893054,
                0.06587930198293179,
                0.03316070802975446,
                0.01680788293015212,
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

var size2el = document.getElementById("size2");
var size2 = new Chart(size2el, {
    type: "horizontalBar",
    options: {
        title: {
            display: true,
            text: "4 threads",
        },
        legend: {
            display: false,
        },
        scales: {
            xAxes: [{
                ticks: {
                    beginAtZero:false
                },
                scaleLabel: {
                    display: true,
                    labelString: 'время, сек'
                }
            }]
        }
    },

    data: {
        labels: ["10^8", "5*10^7", "2.5*10^7", "1.25*10^7"],
         datasets: [{
            label:"время",
            data: [
                0.13197195192333311,
                0.06609878607559949,
                0.03340936300810426,
                0.01710182300303131

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


var size3el = document.getElementById("size3");
var size3 = new Chart(size3el, {
    type: "horizontalBar",
    options: {
        title: {
            display: true,
            text: "4 threads",
        },
        legend: {
            display: false,
        },
        scales: {
            xAxes: [{
                ticks: {
                    beginAtZero:false
                },
                scaleLabel: {
                    display: true,
                    labelString: 'время, сек'
                }
            }]
        }
    },

    data: {
        labels: ["10^8", "5*10^7", "2.5*10^7", "1.25*10^7"],
         datasets: [{
            label:"время",
            data: [
                0.15484936302527785,
                0.07939250092022121,
                0.03906829096376896,
                0.01983976294286549
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
