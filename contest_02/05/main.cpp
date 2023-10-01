
#include <string>  
#include <sstream> 

Complex make_complex(std::string num) {
    Complex c;
    std::istringstream iss(num);
    iss >> c.re;
    char sign;
    iss >> sign;
    iss >> c.im;
    
    if (sign == '-') {
        c.im *= -1;
    }
    return c;
    
}

Complex sum(Complex c1, Complex c2) {
    Complex res;
    res.re = c1.re + c2.re;
    res.im = c1.im + c2.im;
    return res;
}

Complex sub(Complex c1, Complex c2) {
    Complex res;
    res.re = c1.re - c2.re;
    res.im = c1.im - c2.im;
    return res;
}

Complex mul(Complex c1, Complex c2) {
    Complex res;
    res.re = c1.re * c2.re - c1.im * c2.im;
    res.im = c1.re * c2.im + c1.im * c2.re;
    return res;
}

Complex div(Complex c1, Complex c2) {
    Complex res;
    double del = c2.re * c2.re + c2.im * c2.im;
    res.re = (static_cast<float>(c1.re * c2.re + c1.im * c2.im)) / del;
    res.im = (static_cast<float>(c1.im * c2.re - c1.re * c2.im)) / del;
    return res;
}

void print(Complex c) {
    std::cout << c.re;
    if (c.im >= 0) {
        
        if (c.im == -0) {
            std::cout << "+" << 0 << "j" <<std::endl;
        } else {
            std::cout << "+" << c.im << "j" <<std::endl;
        }
        
    } else {
        std::cout << c.im << "j" <<std::endl;
    }
}
