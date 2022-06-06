declare
    a number;
    b number;
    c number;
    rng number;
    num number;
begin
    num:='&number';
    a:=0;
    b:=1;
    c:=0;
    rng:=1;
    while(rng<=num) loop
        dbms_output.put_line(c);
        a:=b;
        b:=c;
        c:=a+b;
        rng:=rng+1;
    end loop;
end;
/