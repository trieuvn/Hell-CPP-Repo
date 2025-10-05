#include <stdio.h>

using ll = long long;

#define MAX_SIZE 1100000

ll store[MAX_SIZE];

ll C4(ll x) {
    ll result = x * (x - 1) * (x - 2) / 6;
    if (result % 4 == 0) return result / 4 * (x - 3);
    if ((x - 3) % 4 == 0) return (x - 3) / 4 * result;
    return (result / 2) * ((x - 3) / 2);
}

int main() {
    ll n, total_parallelogram = 0, unique_numbers = 0, temp_summary = 0, sum_squares = 0;

    scanf("%lld", &n);

    ll arr[n], list_unique_numbers[n];

    for (ll i = 0; i < n; ++i) {
        scanf("%lld", &arr[i]);
        store[arr[i]]++;
        if (store[arr[i]] == 1) {
            list_unique_numbers[unique_numbers++] = arr[i];
        }
    }

    for (ll i = 0; i < unique_numbers; ++i) {
        ll count = store[list_unique_numbers[i]];
        if (count >= 4) {
            total_parallelogram += C4(count);
        }
        list_unique_numbers[i] = (count * (count - 1)) / 2;
    }

    for (ll i = 0; i < unique_numbers; ++i) {
        temp_summary += list_unique_numbers[i];
        sum_squares += list_unique_numbers[i] * list_unique_numbers[i];
    }

    total_parallelogram += (temp_summary * temp_summary - sum_squares) / 2;

    printf("%lld", total_parallelogram);

    return 0;
}
