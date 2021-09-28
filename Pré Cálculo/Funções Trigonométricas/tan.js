let w = 1440;
let h = 810;
let r = 160;
let angle = 90;
let points = [];
let mode = 'sin';
let stopped = 0;
let increment = 0.75;

function setup() {
    let canvas = createCanvas(w, h);
    canvas.position(0,0);   
}
  
function draw() {
    setEnv();
    drawTrig(angle);

    strokeWeight(1);
    stroke(255);
    translate(w/4, 0);
    line(0, -(r + 50), 0, r + 50);
    line(-10, 0, w, 0);
    drawGraph(angle);

    angle += increment;
}

const setEnv = () => {
    background(31);
    translate(w/2 - w/4, h/2);
    noFill();
    stroke(255);
    strokeWeight(3);
    ellipse(0, 0, 2*r, 2*r);

    strokeWeight(1);
    line(-r - 50, 0, r + 50, 0);
    line(0, -r - 50, 0, r + 50);
    line(r, r + 50, r, -r - 50);
    strokeWeight(2);
    line(r-14, 0, r-14, -14);
    line(r-14, -14, r, -14);
    point(r-7, -7);
    
    //line(0, -r - 50, 0, r + 50);
    
}

const drawTrig = (angle) => {
    stroke(255);
    strokeWeight(4);
    line(0, 0, r * sin(radians(angle)), r * cos(radians(angle)));

    strokeWeight(3);
    stroke('aqua');
    line(0, 0, r, r * tan(radians(- angle + 90)));
    stroke('red')
    line(0, 0, r * sin(radians(angle)), 0);
    stroke('yellow');
    line(r * sin(radians(angle)), 0, r * sin(radians(angle)), r * cos(radians(angle)));
   
    stroke(255);
    strokeWeight(13);
    point(r * sin(radians(angle)), r * cos(radians(angle)));

}

const drawGraph = (angle) => {
    strokeWeight(3);
    
    stroke('yellow')
    let dot = createVector(0, r * tan(radians(-angle + 90)));
    points.push(dot);

    for(let i = 1; i < points.length; i++) {
        points[i-1].x += 1;
        if(points[i].y * points[i-1].y > 0)
            line(points[i].x, points[i].y, points[i-1].x, points[i-1].y);
    }
}

/*function mouseClicked() {
    if(mode == 'sin') {
        mode = 'cos';
    } else {
        mode = 'sin';
    }
    points = [];
    angle = 90;
}*/

function keyPressed() {
    if (keyCode == UP_ARROW) {
        if(stopped == 0) {
            noLoop();
            stopped = 1;
        } else {
            stopped = 0;
            loop();
        }
    }
}
