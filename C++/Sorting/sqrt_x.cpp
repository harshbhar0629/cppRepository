            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }return s;
}

int main(){
    int n;
    // vector<int> v;
    cin>>n;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     v.push_back(x);
    // }
    cout<<f(n);
}