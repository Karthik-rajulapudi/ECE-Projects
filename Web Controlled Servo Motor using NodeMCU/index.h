<!--HTML CODE TO CREATE WEBPAGE WITH SLIDER-->

const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<title>ESP8266 Servo | Circuits4you.com</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<style>
.angle{
  width: 79px;
  height: 50px;
  position: absolute;
  vertical-align: middle;
  margin-top: 50px;
  margin-left: -114px;
  border: 0px none;
  background: rgba(0, 0, 0, 0) none repeat scroll 0% 0%;
  font: normal normal bold normal 20px Arial;
  text-align: center;
  color: rgb(34, 34, 34);
  padding: 0px;
}
.spd{
  width: 79px;
  height: 50px;
 position: absolute;
  vertical-align: middle;
  margin-top: 50px;
  margin-left: -114px;
  border: 0px none;
  background: rgba(0, 0, 0, 0) none repeat scroll 0% 0%;
  font: normal normal bold normal 50px Arial;
  text-align: center;
  color: rgb(34, 34, 34);
  padding: 0px;
}
.imageDiv{
    padding: 5%;
 }
.flx{
  display: flex;
}
</style>
<body>
<div style="width:100%;">
<div style="width:50%;  margin: 0 auto;">
  <h3>Circuits4you.com</h3>
  <h4>ESP8266 Servo Motor Control Demo</h4>
</div>
</div>
<div style="width: 50%; margin: 0 auto;" class="flx">
  <svg viewBox="0 0 500 500" width="250" height="250" id="mySVG" style="background:#fff; border: 1px solid black">
  <path fill="none" stroke="#30D8D9"  stroke-width="50" d="M 376.79805300444093 404.6682053761632 A 200 200 0 1 0 121.44247806269212 403.2088886237956"></path>
  <path id="arc1" fill="none" stroke="#00A8A9" stroke-width="50" style="stroke-linecap: round;"/>
  <text x="230" y="260" fill="#777" id="angle" class="spd">0</text>
  <text x="200" y="300" fill="#777" class="angle">Servo Angle</text>
  </svg>
</div>

<script>
function sendData(pos) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
    console.log(this.responseText);
    }
  };
  xhttp.open("GET", "setPOS?servoPOS="+pos, true);
  xhttp.send();
}
function polarToCartesian(centerX, centerY, radius, angleInDegrees) {
  var angleInRadians = (angleInDegrees-90) * Math.PI / 180.0;
  return {
    x: centerX + (radius * Math.cos(angleInRadians)),
    y: centerY + (radius * Math.sin(angleInRadians))
  };
}
function describeArc(x, y, radius, startAngle, endAngle){
    var start = polarToCartesian(x, y, radius, endAngle);
    var end = polarToCartesian(x, y, radius, startAngle);
    var largeArcFlag = endAngle - startAngle <= 180 ? "0" : "1";
    var d = [
        "M", start.x, start.y,
        "A", radius, radius, 0, largeArcFlag, 0, end.x, end.y
    ].join(" ");
    return d;
}
window.onload = function() {
  document.getElementById("arc1").setAttribute("d", describeArc(250, 250, 200, 220, 210));
};
var svg  = document.getElementById("mySVG");
    pt   = svg.createSVGPoint(),
svg.addEventListener('mousedown',function(evt){
  var loc = cursorPoint(evt);
  var degrees = Math.atan2(loc.x-250,loc.y-250)*180/Math.PI + 90;
  var offset = 220;
  degrees = (degrees + 90)
  degrees = degrees + offset;
  if(degrees > 360)
  {
    degrees = degrees - 360;
  }
  degrees = 360 - degrees;
  angle = degrees + offset;
  console.log(degrees, angle);
   if(degrees<281
{
    document.getElementById("arc1").setAttribute("d", describeArc(250, 250, 200, offset, angle));
    var servoAng = Math.round(((angle - 220)/280) * 100);
    document.getElementById("angle").innerHTML=servoAng;
    sendData(servoAng);
  }
});
// Get point in global SVG space
function cursorPoint(evt){
  pt.x = evt.clientX; pt.y = evt.clientY;
  return pt.matrixTransform(svg.getScreenCTM().inverse());
}
</script>
</body>
</html>
)=====";

