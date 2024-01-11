public class Client {
    public static void main(String[] args) {
        Factory factoryA = new ConcreteFactoryA();
        Product productA = factoryA.createProduct();
        productA.display();

        Factory factoryB = new ConcreteFactoryB();
        Product productB = factoryA.createProduct();
        productB.display();
    }
}