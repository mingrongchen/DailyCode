# java工厂模式详解

工厂模式是一种创建型设计模式，其主要目的是提供一种创建对象的接口，但允许子类决定实例化哪个类。工厂模式通过将实例化的过程封装在一个单独的类或方法中，使得客户端代码与具体的类实现解耦。在Java中，有三种主要的工厂模式：简单工厂模式、工厂方法模式和抽象工厂模式。

### 1. 简单工厂模式

简单工厂模式并不是 GoF 设计模式中的一种，但它是一种比较简单实用的工厂模式，通常用来创建同一层次的对象。

#### 示例代码：

```java
javaCopy code// 抽象产品接口
interface Product {
    void display();
}

// 具体产品A
class ConcreteProductA implements Product {
    @Override
    public void display() {
        System.out.println("Concrete Product A");
    }
}

// 具体产品B
class ConcreteProductB implements Product {
    @Override
    public void display() {
        System.out.println("Concrete Product B");
    }
}

// 简单工厂类
class SimpleFactory {
    public static Product createProduct(String type) {
        switch (type) {
            case "A":
                return new ConcreteProductA();
            case "B":
                return new ConcreteProductB();
            default:
                throw new IllegalArgumentException("Invalid product type");
        }
    }
}

// 客户端代码
public class Client {
    public static void main(String[] args) {
        Product productA = SimpleFactory.createProduct("A");
        productA.display();

        Product productB = SimpleFactory.createProduct("B");
        productB.display();
    }
}
```

### 2. 工厂方法模式

工厂方法模式定义了一个创建对象的接口，但由子类决定要实例化的类是哪一个。工厂方法模式使一个类的实例化延迟到其子类。

#### 示例代码：

```java
javaCopy code// 抽象产品接口
interface Product {
    void display();
}

// 具体产品A
class ConcreteProductA implements Product {
    @Override
    public void display() {
        System.out.println("Concrete Product A");
    }
}

// 具体产品B
class ConcreteProductB implements Product {
    @Override
    public void display() {
        System.out.println("Concrete Product B");
    }
}

// 抽象工厂接口
interface Factory {
    Product createProduct();
}

// 具体工厂A
class ConcreteFactoryA implements Factory {
    @Override
    public Product createProduct() {
        return new ConcreteProductA();
    }
}

// 具体工厂B
class ConcreteFactoryB implements Factory {
    @Override
    public Product createProduct() {
        return new ConcreteProductB();
    }
}

// 客户端代码
public class Client {
    public static void main(String[] args) {
        Factory factoryA = new ConcreteFactoryA();
        Product productA = factoryA.createProduct();
        productA.display();

        Factory factoryB = new ConcreteFactoryB();
        Product productB = factoryB.createProduct();
        productB.display();
    }
}
```

### 3. 抽象工厂模式

抽象工厂模式提供了一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。抽象工厂模式与工厂方法模式的区别在于，抽象工厂模式强调一系列产品的创建，而工厂方法模式强调单一产品的创建。

#### 示例代码：

```java
javaCopy code// 抽象产品A
interface ProductA {
    void display();
}

// 具体产品A1
class ConcreteProductA1 implements ProductA {
    @Override
    public void display() {
        System.out.println("Concrete Product A1");
    }
}

// 具体产品A2
class ConcreteProductA2 implements ProductA {
    @Override
    public void display() {
        System.out.println("Concrete Product A2");
    }
}

// 抽象产品B
interface ProductB {
    void show();
}

// 具体产品B1
class ConcreteProductB1 implements ProductB {
    @Override
    public void show() {
        System.out.println("Concrete Product B1");
    }
}

// 具体产品B2
class ConcreteProductB2 implements ProductB {
    @Override
    public void show() {
        System.out.println("Concrete Product B2");
    }
}

// 抽象工厂接口
interface AbstractFactory {
    ProductA createProductA();
    ProductB createProductB();
}

// 具体工厂1
class ConcreteFactory1 implements AbstractFactory {
    @Override
    public ProductA createProductA() {
        return new ConcreteProductA1();
    }

    @Override
    public ProductB createProductB() {
        return new ConcreteProductB1();
    }
}

// 具体工厂2
class ConcreteFactory2 implements AbstractFactory {
    @Override
    public ProductA createProductA() {
        return new ConcreteProductA2();
    }

    @Override
    public ProductB createProductB() {
        return new ConcreteProductB2();
    }
}

// 客户端代码
public class Client {
    public static void main(String[] args) {
        AbstractFactory factory1 = new ConcreteFactory1();
        ProductA productA1 = factory1.createProductA();
        ProductB productB1 = factory1.createProductB();
        productA1.display();
        productB1.show();

        AbstractFactory factory2 = new ConcreteFactory2();
        ProductA productA2 = factory2.createProductA();
        ProductB productB2 = factory2.createProductB();
        productA2.display();
        productB2.show();
    }
}
```

这三种工厂模式在不同场景下有不同的应用。选择合适的工厂模式取决于具体的需求和设计考虑。