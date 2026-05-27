class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        unordered_set<string> s;
        for(string email : emails){
            string temp = "";
            bool ignore = false;

            int i=0;
            while(email[i] != '@'){
                if(email[i] == '+') ignore = true;

                if(!ignore && email[i] != '.') temp += email[i];

                i++;
            }

            while(i < email.length()){
                temp += email[i];
                i++;
            }
            s.insert(temp);
        }
        return s.size();
    }
};