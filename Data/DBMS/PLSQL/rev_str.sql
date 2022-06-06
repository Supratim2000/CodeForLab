declare
    inp varchar2(100);
    rev varchar2(100);
    ln number(3);
begin
    inp:='&string';
    ln:=length(inp);
    for i in 1..ln loop
        rev:=substr(inp,i,1)||rev;
    end loop;
    dbms_output.put_line(rev);
end;
/