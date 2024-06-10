void intToString(int num, char result[], int* pos) {
    if (num == 0) {
        result[(*pos)++] = '0';
        return;
    }

    int digits[10];
    int count = 0;
    if (num < 0) {
        result[(*pos)++] = '-';
        num = -num;
    }
    while (num > 0) {
        digits[count++] = num % 10;
        num /= 10;
    }
    for (int i = count - 1; i >= 0; i--) {
        result[(*pos)++] = '0' + digits[i];
    }
}

int add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {
    int commonDenominator = d1 * d2;
    int numeratorSum = n1 * d2 + n2 * d1;
    int characteristicSum = c1 + c2 + numeratorSum / commonDenominator;
    numeratorSum %= commonDenominator;
    
    int pos = 0;
    intToString(characteristicSum, result, &pos);
    
    result[pos++] = '.';
    
    if (numeratorSum == 0) {
        result[pos++] = '0';
    } else {
        int divisor = commonDenominator / 10;
        while (divisor > 0 && numeratorSum / divisor == 0) {
            result[pos++] = '0';
            divisor /= 10;
        }
        while (divisor > 0) {
            result[pos++] = '0' + numeratorSum / divisor;
            numeratorSum %= divisor;
            divisor /= 10;
        }
    }
    
    result[pos] = '\0';
    return 1;
}

int subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {
    int commonDenominator = d1 * d2;
    int numeratorDiff = n1 * d2 - n2 * d1;
    int characteristicDiff = c1 - c2 + numeratorDiff / commonDenominator;
    numeratorDiff %= commonDenominator;
    
    int pos = 0;
    intToString(characteristicDiff, result, &pos);
    
    result[pos++] = '.';
    
    if (numeratorDiff == 0) {
        result[pos++] = '0';
    } else {
        int divisor = commonDenominator / 10;
        while (divisor > 0 && numeratorDiff / divisor == 0) {
            result[pos++] = '0';
            divisor /= 10;
        }
        while (divisor > 0) {
            result[pos++] = '0' + numeratorDiff / divisor;
            numeratorDiff %= divisor;
            divisor /= 10;
        }
    }
    
    result[pos] = '\0';
    return 1;
}
