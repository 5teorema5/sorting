#include <bits/stdc++.h>
#include <random>
#include <fstream>

const int n = 40;
int a[n];

int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}

std::ofstream f1;

int partition(int arr[], int low, int high, int pivot) {
    int i = low;
    int j = low;
    std::string out;
    while (i <= high) {
        if (arr[i] > pivot) {
            i++;
        } else {
            std::swap(arr[i], arr[j]);
                for (int k = 0; k < low; k++) {
                    out.append(std::to_string(a[k]));
                    out.append(" ");
                }
                for (int k = low; k < high + 1; k++) {
                    out.append(std::to_string(arr[k]));
                    out.append(" ");
                }
                for (int k = high + 1; k < n; k++) {
                    out.append(std::to_string(a[k]));
                    out.append(" ");
                }
            f1 << out << "\n";
            out.clear();
            i++;
            j++;
        }
    }
    return j - 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int pos = partition(arr, low, high, pivot);

        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}


int main() {
    std::string out;
    f1.open("sort_bubble.txt");
    std::vector<int> v1;
    for (int i = 0; i < n; i++) v1.push_back(rand_uns(1, 1000));
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v1.size() - i - 1; j++) {
            if (v1[j] > v1[j + 1]) std::swap(v1[j], v1[j + 1]);
            for (int k = 0; k < n; k++) {
                out.append(std::to_string(v1[k]));
                out.append(" ");
            }
            f1 << out << "\n";
            out.clear();
        }
    }
    f1.close();

    f1.open("sort_insertion.txt");
    std::vector<int> v2;
    for (int i = 0; i < n; i++) v2.push_back(rand_uns(1, 1000));
    int i, k, j;
    for (i = 1; i < v2.size(); i++) {
        k = v2[i];
        j = i - 1;
        while (j >= 0 && v2[j] > k) {
            v2[j + 1] = v2[j];
            j = j - 1;
            for (int k = 0; k < n; k++) {
                out.append(std::to_string(v1[k]));
                out.append(" ");
            }
            f1 << out << "\n";
            out.clear();
        }
        v2[j + 1] = k;
        for (int k = 0; k < n; k++) {
            out.append(std::to_string(v1[k]));
            out.append(" ");
        }
        f1 << out << "\n";
        out.clear();
    }
    f1.close();

    f1.open("sort_comb.txt");
    std::vector<int> v3;
    for (int i = 0; i < n; i++) v3.push_back(rand_uns(1, 1000));
    int gap = n;
    float shrink = 1.3;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = (int) ((float) gap / shrink);
        if (gap < 1) gap = 1;
        swapped = false;
        for (int i = 0; i < n - gap; i++)
            if (v3[i] > v3[i + gap]) {
                std::swap(v3[i], v3[i + gap]);
                swapped = true;
                for (int k = 0; k < n; k++) {
                    out.append(std::to_string(v1[k]));
                    out.append(" ");
                }
                f1 << out << "\n";
                out.clear();
            }
        for (int k = 0; k < n; k++) {
            out.append(std::to_string(v1[k]));
            out.append(" ");
        }
        f1 << out << "\n";
        out.clear();
    }
    f1.close();

    f1.open("sort_quick.txt");
    for (int i = 0; i < n; i++) a[i] = rand_uns(1, 1000);
    quickSort(a, 0, n - 1);
    f1.close();
}
