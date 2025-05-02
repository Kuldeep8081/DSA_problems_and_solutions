class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        
        vector<int> forces(n);
        
        //Move from left to right and look for right force 'R'
        int force = 0; //initially
        for(int i = 0; i<n; i++) {
            if(dominoes[i] == 'R')
                force = n; //My max power towards Right starts from here and it will decrease as I progress
            else if(dominoes[i] == 'L')
                force = 0; //I can't give force towards Right :-(
            else
                force = max(force-1, 0); //I told ya, my power decreases as I progress and hit a '.'
            
            forces[i] = force;
        }
        
        //Move from right to left and look for left force 'L'
        force = 0; //initially
        for(int i = n-1; i>=0; i--) {
            if(dominoes[i] == 'L')
                force = n; //My max power towards Left starts from here and it will decrease as I progress
            else if(dominoes[i] == 'R')
                force = 0; //I can't give force towards Left :-(
            else
                force = max(force-1, 0); //I told ya, my power decreases as I progress and hit a '.'
            
            forces[i] -= force; //resultant force (that's why I am subtracting)
        }
        
        //Now I will find resultant direction on each domino basis of resultant force on them
        string result(n ,'.');
        for(int i = 0; i<n; i++) {
            if(forces[i] < 0)
                result[i] = 'L';
            else if(forces[i] > 0)
                result[i] = 'R';
        }
        return result;
        
    }
};
