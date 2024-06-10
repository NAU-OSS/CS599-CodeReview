int add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {
    int commonDenominator = d1 * d2;
    int numeratorSum = n1 * d2 + n2 * d1;
    int characteristicSum = c1 + c2 + numeratorSum / commonDenominator;
    numeratorSum %= commonDenominator;

    int pos = 0;
    int temp = characteristicSum;

    if (temp < 0) {
        result[pos++] = '-';
        temp = -temp;
    }

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
    int temp = characteristicDiff;

    if (temp < 0) {
        result[pos++] = '-';
        temp = -temp;
    }

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
