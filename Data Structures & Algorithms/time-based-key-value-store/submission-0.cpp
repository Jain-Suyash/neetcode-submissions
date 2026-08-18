class TimeMap
{
private:
    unordered_map<string, vector<pair<string, int>>> mp;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp)
    {
        vector<pair<string, int>> values = mp[key];
        string res = "";
        int low = 0, high = values.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (values[mid].second > timestamp) 
                high = mid - 1;
            else
                low = mid + 1;
        }

        if (high >= 0)
            res = values[high].first;

        return res;
    }
};
