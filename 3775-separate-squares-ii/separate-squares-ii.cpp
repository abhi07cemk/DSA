class Solution {
public:
    struct Event {
        double y;
        double x1, x2;
        int type; // +1 add, -1 remove
    };

    double unionXLength(multiset<pair<double,double>>& segs) {
        if (segs.empty()) return 0.0;
        vector<pair<double,double>> v(segs.begin(), segs.end());
        sort(v.begin(), v.end());

        double len = 0.0;
        double l = v[0].first, r = v[0].second;
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first > r) {
                len += r - l;
                l = v[i].first;
                r = v[i].second;
            } else {
                r = max(r, v[i].second);
            }
        }
        len += r - l;
        return len;
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;

        for (auto &s : squares) {
            double x = s[0], y = s[1], d = s[2];
            events.push_back({y, x, x + d, +1});
            events.push_back({y + d, x, x + d, -1});
        }

        sort(events.begin(), events.end(),
             [](auto &a, auto &b) { return a.y < b.y; });

        multiset<pair<double,double>> active;
        double prevY = events[0].y;
        double totalArea = 0.0;

        vector<pair<double,double>> prefix; // (y, area)

        for (auto &e : events) {
            double currY = e.y;
            double height = currY - prevY;
            if (height > 0) {
                double width = unionXLength(active);
                totalArea += width * height;
                prefix.push_back({currY, totalArea});
            }

            if (e.type == +1)
                active.insert({e.x1, e.x2});
            else
                active.erase(active.find({e.x1, e.x2}));

            prevY = currY;
        }

        double half = totalArea / 2.0;

        // Find Y where prefix area reaches half
        active.clear();
        prevY = events[0].y;
        double currArea = 0.0;

        for (auto &e : events) {
            double currY = e.y;
            double height = currY - prevY;
            if (height > 0) {
                double width = unionXLength(active);
                double nextArea = currArea + width * height;

                if (nextArea >= half) {
                    return prevY + (half - currArea) / width;
                }
                currArea = nextArea;
            }

            if (e.type == +1)
                active.insert({e.x1, e.x2});
            else
                active.erase(active.find({e.x1, e.x2}));

            prevY = currY;
        }
        return prevY;
    }
};
