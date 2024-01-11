class SimpleFactory {
    public static Product createProduct (String type) {
        switch (type) {
            case "A":
                return new ConcreteProductA();
            case "B":
                return new ConcreteProductB();
            default:
                throw new IllegalArgumentException("Invalidproduct type");
        }
    }
}