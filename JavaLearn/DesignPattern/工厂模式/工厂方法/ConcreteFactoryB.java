class ConcreteFactoryB implements Factory {
    public Product createProduct() {
        return new ConcreteProductB();
    }
}