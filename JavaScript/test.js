function Shape() {
	this.x = 0;
	this.y = 0;
}

Shape.prototype.move = function (x, y) {
	this.x += x;
	this.y += y;
	console.info("Shape moved.");
};

function Rectangle() {
    Shape.call(this);
}

Rectangle.prototype = Object.create(Shape.prototype);
Rectangle.prototype.constructor = Rectangle;

var rect = new Rectangle();

console.log(Shape.prototype.move);

console.log(Shape.prototype.constructor === Shape);

console.log(Rectangle.prototype.__proto__ === Shape.prototype);

console.log(Shape.prototype.name);

