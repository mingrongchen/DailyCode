# Java Adapter适配者模式详解

适配器模式（Adapter Pattern）是一种结构型设计模式，用于将一个类的接口转换成客户端期望的另一个接口。适配器允许原本由于接口不匹配而不能一起工作的类能够一起工作。

在Java中，适配器模式可以通过两种方式实现：类适配器和对象适配器。

### 类适配器模式

在类适配器模式中，适配器类继承了被适配的类，并实现了目标接口。这样，适配器就可以通过继承来使用被适配类的方法，并且通过实现目标接口来适配客户端的期望。

```java
javaCopy code// 被适配的类
public class Banner {
    private String string;

    public Banner(String string) {
        this.string = string;
    }

    public void showWithParen() {
        System.out.println("(" + string +")");
    }

    public void showWithAster() {
        System.out.println("*" + string +"*");
    }
}

// 目标接口
public interface Print {
    public abstract void printWeak();
    public abstract void printStrong();
}

// 适配器类（类适配器）
public class PrintBanner extends Banner implements Print {
    public PrintBanner(String string) {
        super(string);
    }

    public void printWeak() {
        showWithParen();
    }

    public void printStrong() {
        showWithAster();
    }
}

/**
 * Adapter extend 客户端
 */
public class main {
    public static void main(String[] args) {

        Print p = new PrintBanner("Hello");
        p.printWeak();
        p.printStrong();

        System.out.println("Adapter end ...");
    }
}
```

### 对象适配器模式

在对象适配器模式中，适配器类持有被适配的类的实例，并实现目标接口。通过组合关系，适配器可以调用被适配类的方法，并通过实现目标接口来适配客户端的期望。

```java
javaCopy code// 被适配的类
public class Banner {
    private String string;

    public Banner(String string) {
        this.string = string;
    }

    public void showWithParen() {
        System.out.println("(" + string +")");
    }

    public void showWithAster() {
        System.out.println("*" + string +"*");
    }
}

// 目标接口
public abstract class Print {
    public abstract void printWeak();
    public abstract void printStrong();
}

// 适配器类（对象适配器）
public class PrintBanner extends Print {
    private Banner banner;
    public PrintBanner(String string) {
        this.banner = new Banner(string);
    }

    public void printWeak() {
        banner.showWithParen();
    }

    public void printStrong() {
        banner.showWithAster();
    }
}

/**
 * Adapter 聚合方式 客户端
 */
public class main {
    public static void main(String[] args) {

        Print p = new PrintBanner("Hello");
        p.printWeak();
        p.printStrong();

        System.out.println("Adapter end ...");
    }
}
```

无论是类适配器还是对象适配器，它们都能够在不修改原有代码的情况下使不同接口的类协同工作。选择适配器模式的具体方式取决于项目的需求和设计考虑。