const rect = {
  x: 10,
  y: 10,
  getSize() {
    return this.x * this.y;
  }
}

const rect2 = Object.create(rect);
console.log(rect.getSize()); // 10*10 = 100
console.log(rect2.getSize()); // 10*10 = 100


rect2.x = 5;
console.log(rect.getSize()); // 10*10 = 100
console.log(rect2.getSize()); // 5*10 = 50

Object.getPrototypeOf(rect2).y = 3;
console.log(rect.getSize()); // 10*3 = 30
console.log(rect2.getSize()); // 5*3 = 15

Object.getPrototypeOf(rect2).x = 3;
console.log(rect.getSize()); // 3*3 = 9
console.log(rect2.getSize()); // 5*3 = 15
