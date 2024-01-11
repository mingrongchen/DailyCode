public class Client {
    public static void main(String[] args) {
        Product productA = SimpleFactory.createProduct("A");
        productA.display();

        Product productB = SimpleFactory.createProduct("B");
        productB.display();
    }
}