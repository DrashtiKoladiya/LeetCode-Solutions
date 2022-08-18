class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int prevDeviceCount = 0, laserCount = 0;
        int nrow = bank.size(), ncolumn = bank[0].size();
        
        for(int i=0;i<nrow;i++)
        {
            int deviceCount = 0;
            for(int j=0;j<ncolumn;j++)
            {
                deviceCount+= (bank[i][j]-'0');
            }
            
            laserCount+= (prevDeviceCount*deviceCount);
            if(deviceCount) prevDeviceCount = deviceCount;
        }
        
        return laserCount;
        
    }
};