class stagger_mins extends uvm_sequence#(basic_seq_item);
    `uvm_object_utils(stagger_mins)

     function new(string name = "stagger_mins");
         super.new(name);
     endfunction: new

     const int TOTAL_MINS = 200;
     const int PLAYERS = 10;
     rand int unsigned starter[5];
     rand int unsigned bench[];

     constraint bench_min_mins {
	 bench.size == PLAYERS - 5; 
	 foreach(bench[i]){
         bench[i] inside {[10:30]};
         }
     }
     constraint starter_min_mins {foreach(starter[i]){
         starter[i]  inside {[20:40]};
         }
     }
     constraint star_min_mins {
         starter[0]  inside {[35:40]};
         starter[1]  inside {[25:40]};
     }
     constraint total_mins {
         starter.sum() + bench.sum() == TOTAL_MINS;
     }

     task body();
     foreach(starter[i]) begin
         `uvm_info("Starter Mins", $sformatf("Starter[%0d] = %0d minutes", i, starter[i]), UVM_LOW)
     end
     foreach(bench[i]) begin
         `uvm_info("Bench Mins  ", $sformatf("Bench[%0d]   = %0d minutes", i, bench[i]), UVM_LOW)
     end
     endtask : body

endclass : stagger_mins     
