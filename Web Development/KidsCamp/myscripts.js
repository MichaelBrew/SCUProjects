var locations = [
      ['Santa Clara University', 37.351971, -121.937828],
      ['San Jose State University', 37.335054, -121.881316],
      ['Stanford University', 37.429359, -122.169642]
];

function removeConfirmation() {
      var box = document.getElementById('ok');
      box.parentNode.removeChild(box);
}

function updateTotal(loggedIn) {
      var total = " $0.00";
	if(document.getElementById('week1').checked && document.getElementById('week2').checked) {
		if(loggedIn) total = " $359.99";
		else total = " $399.99";
	}
	else if(document.getElementById('week1').checked || document.getElementById('week2').checked) {
		if (loggedIn) total = " $179.99";
		else total = " $199.99";
	}
    
	if(loggedIn) ;
	document.getElementById('totalRegistrationPrice').innerHTML = total;
}

function implementMap() {
      var map = new google.maps.Map(document.getElementById('map'), {
                  zoom: 10,
                  center: new google.maps.LatLng(37.351971, -121.937828),
                  mapTypeId: google.maps.MapTypeId.ROADMAP
                });
      var infowindow = new google.maps.InfoWindow();

      var marker, i, currentLocation;

      for (i = 0; i < locations.length; i++) {  
            marker = new google.maps.Marker({
                    position: new google.maps.LatLng(locations[i][1], locations[i][2]),
                    map: map
            });
            google.maps.event.addListener(marker, 'click', (function(marker, i) {
                  return function() {
                        //Update currentLocation
                        currentLocation = locations[i][0];

                        //Show name in map
                        infowindow.setContent(locations[i][0]);
                        infowindow.open(map, marker);
                  }
            })(marker, i));
      }
}

function implementGraph () {
      $(function() {

            var scu = [],
                  sjsu = [],
                  su = [];

            //Enter graph data here
            var year = 2003;
	    
	    scu.push([year, 20]);
	    sjsu.push([year, 15]);
	    su.push([year, 23]);
	    year++;
	
	    scu.push([year, 30]);
	    sjsu.push([year, 20]);
	    su.push([year, 30]);
	    year++;

	    scu.push([year, 50]);
	    sjsu.push([year, 24]);
	    su.push([year, 35]);
	    year++;
	
	    scu.push([year, 70]);
	    sjsu.push([year, 29]);
	    su.push([year, 47]);
	    year++;

	    scu.push([year, 100]);
	    sjsu.push([year, 35]);
	    su.push([year, 52]);
	    year++;

	    scu.push([year, 110]);
	    sjsu.push([year, 38]);
	    su.push([year, 60]);
	    year++;

	    scu.push([year, 115]);
	    sjsu.push([year, 40]);
	    su.push([year, 65]);
	    year++;

	    scu.push([year, 120]);
	    sjsu.push([year, 43]);
	    su.push([year, 70]);
	    year++;

	    scu.push([year, 120]);
	    sjsu.push([year, 50]);
	    su.push([year, 75]);
	    year++;

	    scu.push([year, 125]);
	    sjsu.push([year, 60]);
	    su.push([year, 77]);
	    year++;

            var plot = $.plot("#graph", [
                  { data: scu, label: "SCU"},
                  { data: sjsu, label: "SJSU"},
                  { data: su, label: "Stanford"}
            ], {
                  series: {
                        lines: {
                              show: true
                        },
                        points: {
                              show: true
                        }
                  },
                  grid: {
                        hoverable: true,
                        clickable: true
                  },
                  yaxis: {
                        min: 0,
                        max: 130
                  }
            });

            $("<div id='tooltip'></div>").css({
                  position: "absolute",
                  display: "none",
                  border: "1px solid #fdd",
                  padding: "2px",
                  "background-color": "#fee",
                  opacity: 0.80
            }).appendTo("body");

            $("#graph").bind("plothover", function (event, pos, item) {

                  if ($("#enablePosition:checked").length > 0) {
                        var str = "(" + pos.x.toFixed(2) + ", " + pos.y.toFixed(2) + ")";
                        $("#hoverdata").text(str);
                  }

                        if (item) {
                              var x = item.datapoint[0].toFixed(2),
                                    y = item.datapoint[1].toFixed(2);

                              $("#tooltip").html(parseInt(y) + " kids enrolled in " + parseInt(x))
                                    .css({top: item.pageY+5, left: item.pageX+5})
                                    .fadeIn(200);
                        } else {
                              $("#tooltip").hide();
                        }
                  
            });

            $("#graph").bind("plotclick", function (event, pos, item) {
                  if (item) {
                        $("#clickdata").text(" - click point " + item.dataIndex + " in " + item.series.label);
                        plot.highlight(item.series, item.datapoint);
                  }
            }); 
      });

}