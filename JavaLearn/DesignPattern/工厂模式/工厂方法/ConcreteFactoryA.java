class ConcreteFactoryA implements Factory {
    public Product createProduct() {
        return new ConcreteProductA();
    }
}