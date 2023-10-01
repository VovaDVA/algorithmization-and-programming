auto reduce(int m, int n) 
{
    int m1, n1;
    int minN = std::max(std::abs(m), std::abs(n));
  
    for (int i = 1; i <= minN; i++) {
        if (m % i == 0 && n % i == 0) {
            m1 = m / i;
            n1 = n / i;
        }
    }

    return std::tuple(m1, n1);
}

auto find_lcm(int n1, int n2)
{
    int lcm, c, d;
    int prod = std::abs(n1 * n2);
    int minN = std::min(std::abs(n1), std::abs(n2));

    for (int i = minN; i <= prod; i++) {
        if (i % n1 == 0 && i % n2 == 0 && i != 0) {
            lcm = i;
            c = i / n1;
            d = i / n2;
            break;
        }
    }

    struct result { int l; int c; int d; };
    return result { lcm, c, d };
}
