import java.util.*;

class A {
    int a;
}

class B : public A {
    int b;
}

class Main {
    public static void main(String[] args) {
        A temp = new A();
        temp.a = 10;
        A temp = new B();

    }
}