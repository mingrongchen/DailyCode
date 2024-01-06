#define PI 6

class Test {
    public:

        Test() {}
        typedef int(*FunType)(int, int);
        void Add(FunType fun, int a, int b) {
            int sum = fun(a, b);
            std::cout << "sum: " << sum << std::endl;
        }
};