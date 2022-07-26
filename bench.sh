#!/usr/bin/env sh

run(){
  echo $1
  $1 | pv -r >/dev/null &
  BENCH_PID=$!
  sleep 3;
  kill $BENCH_PID
  echo
}

run ./yes
run yes
