//Genera todas las permutaciones en Orden lexicografico
//  La secuencia debe estar previamente ordenada para que funcione
vector<int> v = {1, 2, 3};
do {for (int x : v)cout << x << ' ';
  cout << '\n';
} while (next_permutation(v.begin(), v.end()));
// Salidas 1 2 3 // 1 3 2 // 2 1 3 // 2 3 1 // 3 1 2 // 3 2 1
