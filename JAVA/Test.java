class Box<T> {
    T a;

    void set(T a) {
        this.a = a;
    }

    T get() {
        return this.a;
    }
};

class Box2<T> {
    Box<T> A = new Box<T>();

    void set(T a) {
        A.set(a);
    }

    void show() {
        System.out.println(A.get());
    }
};

public class Test {
    public static void main(String[] args) {
        Box2<Integer> B = new Box2<Integer>();
        B.set(10);
        B.show();
    }
}