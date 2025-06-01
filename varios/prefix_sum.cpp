vector<int> v = {1, 2, 3, 4, 5};
vector<int> prefix(v.size());
partial_sum(v.begin(), v.end(), prefix.begin()//posicion desde la que se
//construira); 
for (int x : prefix)
    cout << x << " ";
// Output: 1 3 6 10 15


