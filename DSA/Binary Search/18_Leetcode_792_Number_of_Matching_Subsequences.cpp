
/*
|>------------------------------------------------------------------------------------------------------------------------------------------------------------
|>                               █▀ ▀█▀ █▀▀ █░░ █░░ █░█ █▀█
|>                               ▄█ ░█░ ██▄ █▄▄ █▄▄ █▀█ █▀▄
|>------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define MOD 1000000007
#define MOD1 998244353
#define PI 3.141592653589793238462

typedef long long ll;

// |> ---DEBUG_TEMPLATE_START---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    return os << '{' << p.first << ", " << p.second << '}';
}

template <class T, class = decltype(begin(declval<T>())),
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c)
{
    os << '[';
    for (auto it = begin(c); it != end(c); ++it)
        os << (it == begin(c) ? "" : ", ") << *it;
    return os << ']';
}

// Specialization for unordered_map
template <class Key, class T, class Hash, class Pred, class Alloc>
ostream &operator<<(ostream &os, const unordered_map<Key, T, Hash, Pred, Alloc> &m)
{
    os << '{';
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        os << it->first << ": " << it->second;
        auto next = it;
        ++next;
        if (next != m.end())
        {
            os << ", ";
        }
    }
    os << '}';
    return os;
}

#define _NTH_ARG(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define _FE_6(_CALL, x, ...) _CALL(x) _FE_5(_CALL, __VA_ARGS__)
#define _FE_7(_CALL, x, ...) _CALL(x) _FE_6(_CALL, __VA_ARGS__)
#define _FE_8(_CALL, x, ...) _CALL(x) _FE_7(_CALL, __VA_ARGS__)
#define _FE_9(_CALL, x, ...) _CALL(x) _FE_8(_CALL, __VA_ARGS__)
#define _FE_10(_CALL, x, ...) _CALL(x) _FE_9(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                                               \
    _NTH_ARG(__VA_ARGS__, _FE_10, _FE_9, _FE_8, _FE_7, _FE_6, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1) \
    (MACRO, __VA_ARGS__)

// Change output format here
#define out(x) #x " = " << x << "; "

#ifndef ONLINE_JUDGE
#define debug(...) \
    cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define debug(...)
#endif

//|> ---DEBUG_TEMPLATE_END-----------------------------------------------------------------------------------------------------------------------------------------------------------

// #define FOR(i, start, end) for (int i = start; i < end; i++)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define RFOR(i, start, end) for (int i = end; i >= start; i--)
#define FOREACH(x, b) for (auto x : b)

#define cout1(x) cout << x << endl;
#define cout2(x, y) cout << x << " " << y << endl;
#define cout3(x, y, z) cout << x << " " << y << " " << z << endl;

#define SUMOFN(arr) accumulate(arr.begin(), arr.end(), 0LL);
#define SORTASC(arr) sort(arr.begin(), arr.end());
#define SORTDSC(arr) sort(arr.begin(), arr.end(), greater<int>());
#define REV(arr) reverse(arr.begin(), arr.end());

#define strLow(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define strUp(s) transform(s.begin(), s.end(), s.begin(), ::toupper);

#define lb(arr, ele) lower_bound(arr.begin(), arr.end(), ele);
#define ub(arr, ele) upper_bound(arr.begin(), arr.end(), ele);

typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> stint;
typedef map<int, int> mpint;
typedef pair<int, int> pi;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

//|> ---ＳＯＬＶＥ-----------------------------------------------------------------------------------------------------------------------------------------------
bool hasWord(string w, string s)
{
    int i = 0;
    int j = 0;
    while (i < w.size() && j < s.size())
    {
        if (w[i] == s[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return i == w.size();
}

int numMatchingSubseq(string s, vector<string> &words)
{
    int res = 0;
    for (auto word : words) // |> O(words.size())
    {
        if (hasWord(word, s))
        {
            res++;
        }
    }
    return res;
}

void printMap(map<char, vector<int>> &mpp)
{
    for (const auto &entry : mpp)
    {
        char ch = entry.first;
        const vector<int> &indices = entry.second;

        cerr << "Character: " << ch << ", Indices: ";
        for (int index : indices)
        {
            cerr << index << " ";
        }
        cerr << endl;
    }
}
int numMatchingSubseqOP(string s, vector<string> &words)
{
    map<char, vector<int>> mpp;
    vector<vector<int>> mapping(26);

    for (int i = 0; i < s.size(); i++) //|>  O(s.size())
    {
        char ch = s[i];
        int indx = i;
        mpp[ch].push_back(indx);
    }

    printMap(mpp);

    int res = 0;
    for (auto word : words) //|>  O(words.size())
    {
        bool wordFound = true;

        for (int i = 0, prevIndex = -1; wordFound && i < word.size(); i++) //|>  O(word.size())
        {
            char currCharOfWord = word[i];
            auto &vec = mpp[currCharOfWord];
            auto iter = upper_bound(begin(vec), end(vec), prevIndex); //|>  O(logN)
            if (iter == vec.end())
            {
                wordFound = false;
            }
            else
            {
                prevIndex = *iter;
            }
        }
        res += wordFound;
    }
    return res;
}

void solve()
{
    vector<string> words;
    string w;
    while (cin >> w && w != "#")
    {
        words.push_back(w);
    }
    string s;
    cin >> s;
    int res = numMatchingSubseqOP(s, words);
    debug(res);
}

//|> ---MAIN-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("../../Error.txt", "w", stderr);
    freopen("../../output.txt", "w", stdout);
    freopen("../../input.txt", "r", stdin);
#endif
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}
