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
