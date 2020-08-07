class preemptivesjf {

    static class Process {
        int arrival_time ;
        int burst_time ;
        int completion_time ;

        public Process(int arrival_time , int burst_time){
            this.arrival_time = arrival_time ;
            this.burst_time = burst_time ;
        }
    }


    public static void main(String[] args) {
        
        Process []prc = new Process[4];
        prc[0] = new Process(1, 6);
        prc[1] = new Process(1, 8);
        prc[2] = new Process(2, 7);
        prc[3] = new Process(3, 3);

        simulate_process(prc, 4);


        System.out.println("Turn around time");

        for(int i=0;i<4;++i){
            System.out.println( (prc[i].completion_time - prc[i].arrival_time )+" ");
        }

    }

    public static void simulate_process(Process[] pro, int n) {

        int []rt = new int[n];

        for(int i=0;i<n;++i){
            rt[i]=pro[i].burst_time ;
        }

        int comp_process = 0 ;
        int min_rt = Integer.MAX_VALUE ;
        boolean isAnyoneSelected = false ;
        int time =0 ;

        int min_rt_pro_index =0 ;
        while(comp_process!=n) {

                for(int i=0;i<n;++i){
                    if(rt[i]>0 && (rt[i]<min_rt && pro[i].arrival_time <= time)){
                        min_rt_pro_index = i ;
                        min_rt = rt[i];
                        isAnyoneSelected = true; 
                    }
                }

                if(!isAnyoneSelected) {
                    time++;
                    continue;
                }

                
                rt[min_rt_pro_index]--;

                if(rt[min_rt_pro_index] == 0){
                    pro[min_rt_pro_index].completion_time = time+1;
                    min_rt = Integer.MAX_VALUE;
                    comp_process++;
                }
                time++;
        }

    }
}