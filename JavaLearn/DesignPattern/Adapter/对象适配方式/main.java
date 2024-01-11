/**
 * Adapter 聚合方式
 */
public class main {
    public static void main(String[] args) {

        Print p = new PrintBanner("Hello");
        p.printWeak();
        p.printStrong();

        System.out.println("Adapter end ...");
    }
}