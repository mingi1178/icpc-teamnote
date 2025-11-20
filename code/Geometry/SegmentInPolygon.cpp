// WARNING: C.push_back(C[0]) before call function
bool segment_in_polygon_non_strict(vector<P> &C, P s, P e){
    if(!pip(C, s) || !pip(C, e)) return false;
    if(s == e) return true; P d = e - s;
    vector<pair<frac,int>> v; auto g=raypoints(C, s, d, v);
    for(auto [fr,ev] : v){ // in(06) out(27)
        if(fr.first < 0 || g < fr) continue;
        if(ev == 4) return false; // pass outside corner
        if(fr < g && (ev == 2 || ev == 7)) return false;
        if(0 < fr.first && (ev == 0 || ev == 6)) return false;
    } return true;
}