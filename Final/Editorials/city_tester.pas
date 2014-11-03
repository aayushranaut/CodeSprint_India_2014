(* Pascal *) 
program problemTheMostBeautifulCity;
uses sysutils;

procedure assert( ok: boolean; err: ansistring );
begin
    if ( not ok ) then
    begin
        writeln( err );

        halt( 1 );
    end;
end;

var n, k, i, j, x: longInt;
    cnt, ans: array[ 1..1000000 ] of longInt;

begin
    fillchar( cnt, sizeOf(cnt), 0 );
    fillchar( ans, sizeOf(ans), 0 );

    readln( n, k );

    assert( ( n >= 1 ) and ( n <= round(1.0e+6) ), 'n violates the constraints' );
    assert( ( k >= 1 ) and ( k <= round(1.0e+6) ), 'k violates the constraints' );

    for i := 1 to n do
        for j := 1 to n div i do
            inc( cnt[i * j] );

    for i := 1 to k do
    begin
        read( x );

        assert( ( x >= 1 ) and ( x <= n ), 'the most beautiful city of traveler ' + intToStr(i) + ' violates the constraints, outside the range [1, n]' );

        inc( ans[x] );
    end;

    for i := 1 to n do
        if ( odd( cnt[i] ) ) and ( ans[i] > 0 ) then
            writeln( i, ' ', ans[i] );
end.