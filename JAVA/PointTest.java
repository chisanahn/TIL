
class Point {
    int x, y;

    Point() {
        this.x = 0;
        this.y = 0;
    }

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    String getLocation() {
        return "x: " + x + ", y: " + y;
    }
}

class Point3D extends Point {
    int z;

    Point3D(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

}