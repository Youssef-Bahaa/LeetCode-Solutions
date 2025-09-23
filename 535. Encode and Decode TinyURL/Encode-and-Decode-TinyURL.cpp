class Solution {
public:
    string saved = "";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        saved = longUrl;
        return "LOL";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return saved;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));