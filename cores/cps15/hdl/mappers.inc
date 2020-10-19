// Only mappers needed for CPS 1.5

6'h25: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==OBJ  ) /* 0 - 7fff */
        ||  ( layer==SCR2 ) /* 0 - 7fff */
        ||  ( layer==SCR1 ) /* 0 - 7fff */
        ||  ( layer==SCR3  && code[15:14]==2'b00 ) /* 0 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_b[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */
        ||  ( layer==SCR2  && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */
        ||  ( layer==SCR1  && code[15:10]>=7'h20 && code[15:10]<=7'h3f) /* 8000 - ffff */
        ||  ( layer==SCR3  && code[13:7]>=7'h20 && code[13:7]<=7'h3f && code[15:14]==2'b00 ) /* 8000 - ffff */ ;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
6'h5: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==SCR1  && code[15:10]<=7'h3) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:9]>=7'h4) /* 1000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_b[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h37) /* 8000 - dfff */
        ||  ( layer==SCR2  && code[15:9]>=7'h20 && code[15:9]<=7'h37) /* 8000 - dfff */  ||
         ( layer==SCR3  && code[13:7]>=7'h38 && code[13:7]<=7'h3f && code[15:14]==2'b00 ) /* e000 - ffff */ ;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
6'h17: begin
        // Bank 0 size 0x08000
        bank_b[0] <=  ( layer==SCR1  && code[15:10]<=7'h3) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:9]>=7'h4) /* 1000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_b[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h36) /* 8000 - dbff */
        ||  ( layer==SCR2  && code[15:9]>=7'h20 && code[15:9]<=7'h36) /* 8000 - dbff */  ||
         ( layer==SCR3  && code[13:7]>=7'h37 && code[13:7]<=7'h3f && code[15:14]==2'b00 ) /* dc00 - ffff */ ;
        bank_b[2] <= 1'b0;
        bank_b[3] <= 1'b0;
        set_used  <= 1'b1;
    end
6'h10: begin
        // Bank 0 size 0x08000
        bank_a[0] <=  ( layer==SCR1  && code[15:10]<=7'h3) /* 0 - fff */  ||
         ( layer==OBJ   && code[15:9]>=7'h4) /* 1000 - 7fff */
        ||  ( layer==SCR2  && code[15:9]>=7'h4) /* 1000 - 7fff */ ;
        // Bank 1 size 0x08000
        bank_a[1] <=  ( layer==OBJ   && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */
        ||  ( layer==SCR2  && code[15:9]>=7'h20 && code[15:9]<=7'h3f) /* 8000 - ffff */ ;
        // Bank 2 size 0x08000
        bank_a[2] <=  ( layer==OBJ   && code[15:9]>=7'h40 && code[15:9]<=7'h59) /* 10000 - 167ff */
        ||  ( layer==SCR2  && code[15:9]>=7'h40 && code[15:9]<=7'h59) /* 10000 - 167ff */  ||
         ( layer==SCR3  && code[13:7]>=7'h5a && code[13:7]<=7'h5f && code[15:14]==2'b00 ) /* 16800 - 17fff */ ;
        bank_a[3] <= 1'b0;
        set_used  <= 1'b0;
    end