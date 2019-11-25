#include <iostream>

struct SA {
    int i;
    SA():i(2){std::cout << "default constructor called" << std::endl;}
    SA(SA &&rr):i(rr.i){std::cout << "move constructor called" << std::endl;}
    SA(const SA &r):i(r.i){std::cout << "copy constructor called" << std::endl;}
    ~SA() = default;
    SA& operator=(const SA& r) {i = r.i;return *this;}
    SA& operator=(SA &&r) {i = r.i;return *this;}
};



void f(const SA& acr) {
    std::cout << "lvalue reference version called" << std::endl;
}
void f(SA &&arr) {
    std::cout << "rvalue reference version called" << std::endl;
}
int main(void) {
    SA sa;

    SA sao = sa;
    SA &&sarr = std::move(sa);
    SA &sar = sa;
    SA saa(sarr);
    SA sarn(std::move(sarr));

    f(sa);
    f(sar);
    f(sarr);
    f(std::move(sar));



    // Note:all decltype of sa,sac,sarr,sarrc,sar,sarc expression are lvalue

    /*
    decltype((sarr)) dkfj = sa;
    SA sab = sa;
    SA sacb = sac;
    SA sarrb = sarr;
    SA sarrcb = sarrc;
    SA sarb = sar;
    SA sarcb = sarc;

    const SA sabc = sa;
    const SA sacbc = sac;
    const SA sarrbc = sarr;
    const SA sarrcbc = sarrc;
    const SA sarbc = sar;
    const SA sarcbc = sarc;

    SA &sad = sa;
    //SA &sacd = sac; // lvalue reference can not bind to const lvalue
    SA &sarrd = sarr;
    //SA &sarrcd = sarrc; // lvalue reference can not bind to const xvalue
    SA &sard = sar;
    //SA &sarcd = sarc; // lvalue reference can not bind to const lvalue
    //SA &sarrrr = std::move(sa); // no-const lvalue reference cannot bind to rvalue

    // const lvalue reference can bind to all value
    const SA &sadc = sa;
    const SA &sacdc = sac;
    const SA &sarrdc = sarr;
    const SA &sarrcdc = sarrc;
    const SA &sardc = sar;
    const SA &sarcdc = sarc;
    const SA &sarrrr = std::move(sa);


    //SA &&sae = sa; // rvalue reference can not bind to lvalue
    //SA &&sace = sac; // rvalue reference can not bind to const lvalue
    //decltype((sarr)) sarree = sarr; // can compile, decltype(sarr) is SA&&,but decltype((sarr)) is SA&
    //decltype(sarr) sarree = sarr; // can not compile, decltype(sarr) is SA&&,but decltype((sarr)) is SA&
    //SA &&sarre = sarr;
    //SA &&sarrce = sarrc;
    //SA &&sare = sar;
    //SA &&sarec = sarc;
    //Note: all no-const reference cannot bind to const value

    //const SA &&saec = sa;
    //const SA &&sacec = sac;
    //const SA &&sarre = sarr;
    //const SA && sarrcec = sarrc;
    //const SA &&sare = sar;
    //const SA &&sarce = sarc;
    //Note:rvalue reference can only bind to rvalue(including prvalue and xvalue) expression
    */

    return 0;
}
