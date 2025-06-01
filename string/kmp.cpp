/*
 * KMP - Knuth-Morris-Pratt
 * Busca todas las ocurrencias del patron en el texto
 * Complejidad: O(n + m), donde n = tamano del texto, m = tamano del patron
 */

vector<int> prefix_function(const string &pat) {
    int m = pat.size();
    vector<int> pi(m);
    for (int i = 1; i < m; ++i) {
        int j = pi[i - 1];
        while (j > 0 && pat[i] != pat[j])
            j = pi[j - 1];
        if (pat[i] == pat[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp_search(const string &text, const string &pat) {
    vector<int> pi = prefix_function(pat);
    vector<int> occ;
    int n = text.size(), m = pat.size(), j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pat[j])
            j = pi[j - 1];
        if (text[i] == pat[j])
            ++j;
        if (j == m) {
            occ.push_back(i - m + 1); // ocurrencia encontrada
            j = pi[j - 1];
        }
    }
    return occ;
}

/*
 * Z-Algorithm
 * Z[i] = longitud del prefijo comun entre s y s[i..]
 * Sirve para buscar un patron en texto en O(n + m)
 */

vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

// Buscar patron en texto usando Z-function
vector<int> z_search(const string &text, const string &pat) {
    string s = pat + '#' + text;
    vector<int> z = z_function(s);
    vector<int> occ;
    int m = pat.size();
    for (int i = m + 1; i < (int)s.size(); ++i) {
        if (z[i] == m)
            occ.push_back(i - m - 1); // ocurrencia en texto
    }
    return occ;
}

