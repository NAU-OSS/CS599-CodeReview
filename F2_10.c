int add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {
    int commonDenominator = d1 * d2;
    int numerator1 = c1 * commonDenominator + n1 * d2;
    int numerator2 = c2 * commonDenominator + n2 * d1;
    int numeratorSum = numerator1 + numerator2;

    int pos = 0;

    if (numeratorSum < 0) {
        result[pos++] = '-';
        numeratorSum = -numeratorSum;
    }

    int characteristicSum = numeratorSum / commonDenominator;
    int temp = characteristicSum;
    if (temp == 0) {
        result[pos++] = '0';
    } else {
        int divisor = 1;
        while (temp / divisor >= 10) {
            divisor *= 10;
        }
        while (divisor > 0) {
            result[pos++] = '0' + temp / divisor;
            temp %= divisor;
            divisor /= 10;
        }
    }

    result[pos++] = '.';

    numeratorSum %= commonDenominator;
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
    int numerator1 = c1 * commonDenominator + n1 * d2;
    int numerator2 = c2 * commonDenominator + n2 * d1;
    int numeratorDiff = numerator1 - numerator2;

    int pos = 0;

    if (numeratorDiff < 0) {
        result[pos++] = '-';
        numeratorDiff = -numeratorDiff;
    }

    int characteristicDiff = numeratorDiff / commonDenominator;
    int temp = characteristicDiff;
    if (temp == 0) {
        result[pos++] = '0';
    } else {
        int divisor = 1;
        while (temp / divisor >= 10) {
            divisor *= 10;
        }
        while (divisor > 0) {
            result[pos++] = '0' + temp / divisor;
            temp %= divisor;
            divisor /= 10;
        }
    }

    result[pos++] = '.';

    numeratorDiff %= commonDenominator;
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
