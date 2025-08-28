#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false), cout.tie(0);
    int n;cin>>n;
    int a[n]; for(auto &x:a) cin>>x;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    bool vis[105][105];memset(vis,0,sizeof vis);
    bool ok=0;
    while (!pq.empty()) {
        int cur=pq.top().first, h=pq.top().second;
        pq.pop();
        if (cur==24) {
            ok=1;
            break;
        }
        if (vis[cur][h]) continue; 
        vis[cur][h]=1;
        int best=0;
        for (int i=0;i<n;i++) {
            int tambah=cur+a[i];
            int kurang=cur-a[i];
            int bagi=cur/a[i];
            int kali=cur*a[i];
            int htambah=abs(24-tambah);
            int hkurang=abs(24-kurang);
            int hbagi=abs(24-bagi);
            int hkali=abs(24-kali);
            if (htambah<=hkurang && htambah<=hkali && htambah<=hbagi) pq.push({tambah,htambah});
            if (hkurang<=htambah && hkurang<=hkali && hkurang<=hbagi) pq.push({kurang,hkurang});
            if (hkali<=htambah && hkali<=hkurang && hkali<=hbagi) pq.push({kali,hkali});
            if (hbagi<=htambah && hbagi<=hkurang && hbagi<=htambah) pq.push({bagi,hbagi});
        }
    }
    if (ok) cout << "Yes";
    else cout << "No";
    return 0;
}
