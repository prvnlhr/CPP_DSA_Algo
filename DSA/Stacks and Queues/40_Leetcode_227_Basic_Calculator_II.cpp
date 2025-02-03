
/*

 ▄▀█ █░█ █▀▄▀█ █▄░█ █▀█ █▀▄▀█
 █▀█ █▄█ █░▀░█ █░▀█ █▄█ █░▀░█

*/

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

//__________________________________________________________________________________________________________________________________________________________________________________________________

#define MOD 1000000007
#define MOD1 998244353
#define PI 3.141592653589793238462

typedef long long ll;

//>---DEBUG_TEMPLATE_START---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    return os << '{' << p.first << ", " << p.second << '}';
}

template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c)
{
    os << '[';
    for (auto it = c.begin(); it != c.end(); ++it)
        os << &", "[2 * (it == c.begin())] << *it;
    return os << ']';
}
//__support up to 5 args
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                           \
    _NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0) \
    (MACRO, ##__VA_ARGS__)

//__Change output format here
#define out(x) #x " = " << x << "; "

#ifndef ONLINE_JUDGE
#define debug(...) \
    cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define debug(...)
#endif

//>---DEBUG_TEMPLATE_END-----------------------------------------------------------------------------------------------------------------------------------------------------------

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
//_____________________________
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
//_____________________________
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
//__factorial______________________________________________
vector<ll> fact;
void factOfN(ll n)
{
    ll prod = 1;
    fact.resize(n + 1);
    for (int f = 1; f <= n; f++)
    {

        fact[f] = prod * f;
        prod = prod * f;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------

//>----------------------------ＳＯＬＶＥ-----------------------------------------------------------------------------------------------------------------------------------------------

int calculate(string s)
{
    int n = s.size();
    int iter = 0;

    string snew = "";
    while (iter < n)
    {
        if (s[iter] != ' ')
        {
            snew += s[iter];
        }
        iter++;
    }

    s = snew;
    n = snew.size();

    vector<int> operands;
    vector<char> operators;
    int res = 0;
    long long num = 0;

    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        {
            while (i < n && isdigit(s[i]))
            {
                num = (num * 10) + (s[i] - '0');
                i++;
            }
            operands.push_back(num);
            num = 0;
            i--;
        }
        else if (!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1)
        {
            if (s[i] == '+')
            {
                operators.push_back(s[i]);
            }
            else if (s[i] == '-')
            {
                operators.push_back(-s[i]);
            }
            else
            {
                char op = s[i];
                i++;
                int num1 = 0;
                while (i < n && isdigit(s[i]))
                {
                    num1 = (num1 * 10) + (s[i] - '0');
                    i++;
                }
                i--;
                int num2 = operands.back();
                operands.pop_back();
                long long currRes = 0;
                if (op == '*')
                {
                    currRes = num1 * num2;
                }
                else
                {
                    currRes = num2 / num1;
                }
                operands.push_back(currRes);
            }
        }
    }

    int result = operands[0];

    // calculating result from left to right according to BODMASS( if add or sub then do operations from left to right)
    for (int i = 0; i < operators.size(); i++)
    {
        if (operators[i] == '+')
        {
            result += operands[i + 1];
        }
        else if (operators[i] == '-')
        {
            result -= operands[i + 1];
        }
    }

    return result;
}

int calculateBetter(string s)
{

    int n = s.size();

    stack<int> operands;
    int currNum = 0;
    char op = '+';

    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        {
            currNum = (currNum * 10) + int(s[i] - '0');
        }
        if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1)
        {
            if (op == '+')
            {
                operands.push(currNum);
            }
            else if (op == '-')
            {
                operands.push(-currNum);
            }
            else
            {
                int currRes;
                if (op == '*')
                {
                    currRes = operands.top() * currNum;
                }
                else
                {
                    currRes = operands.top() / currNum;
                }
                operands.pop();
                operands.push(currRes);
            }
            op = s[i];
            currNum = 0;
        }
    }

    int result = 0;

    while (!operands.empty())
    {
        result += operands.top();
        operands.pop();
    }
    return result;
}

void solve()
{
    // string s = "0-2147483647";
    // string s = "1-1+1";
    string s = "3+2*2";

    cout << calculateBetter(s) << endl;
}

//>-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
    auto now = system_clock::to_time_t(system_clock::now());
    stringstream timeStream;

    timeStream << put_time(localtime(&now), "%d %b %Y %H:%M:%S");
    string formatted_time = timeStream.str();

#ifndef ONLINE_JUDGE
    cerr << endl;
    cerr << "Exec Time: " << duration.count() / 1000 << " ms" << endl;
    cerr << "Curr Time: " << formatted_time << endl;
#endif
}
