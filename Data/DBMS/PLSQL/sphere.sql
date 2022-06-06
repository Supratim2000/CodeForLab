declare
    r sphere.rad%type;
    a sphere.area%type;
    v sphere.volume%type;
begin
    for i in 1..20 loop
        r:=i;
        a:=4*3.14*r*r;
        v:=4/3*3.14*r*r*r;
        insert into sphere values(r,a,v);
    end loop;
end;
/