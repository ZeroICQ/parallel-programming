var SpeedFromThreads1BillionElement = document.getElementById("SpeedFromThreads1Billion");

var SpeedFromThreads1Billion = new Chart(SpeedFromThreads1BillionElement, {
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

var spongeBobImg = new Image();
spongeBobImg.src = "https://www.soyhomosensual.com/wp-content/uploads/2017/12/spongebob-gay.jpg"
spongeBobImg.onload = function() {
    var SpeedFromThreads1MillionElement = document.getElementById("SpeedFromThreads1Million");
    var fillPattern = SpeedFromThreads1MillionElement.getContext("2d").createPattern(spongeBobImg, 'repeat');

    var SpeedFromThreads1Billion = new Chart(SpeedFromThreads1MillionElement, {
        type: "horizontalBar",
        options: {
            title: {
                display: true,
                text: "16^6",
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
