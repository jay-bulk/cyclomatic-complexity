use core::ops::Index;
use core::ops::RangeFull;

fn main() {
    let stg:i32 = 0;
    let input:&dyn Index<RangeFull> = "Default";
    let error_switch:String = "no".to_string();

    CheckBoeingString(input, stg, error_switch);
    return;
}
fn CheckBoeingString(input:&dyn Index<RangeFull, Output = char>, stg:i32, error_switch:String) {
    if input[stg] == 'B' {
        stg += 1;
    } else {
        error_switch = "yes".to_string();
        CheckEndString(input, stg);
    }
    if *input[stg] == '-' {
        stg += 1;
    } else {
        error_switch = "yes".to_string();
        CheckEndString(input, stg);
    }
    if input[stg] == '7' {
        stg += 1;
    } else {
        error_switch = "yes".to_string();
        CheckEndString(input, stg);
    }
    if input[stg] == '3' || input[stg] == '4' || input[stg] == '5' || input[stg] == '6' || input[stg] == '7' || input[stg] == '8' {
        stg += 1;
    } else {
        error_switch = "yes".to_string();
        CheckEndString(input, stg);
    }
}
fn CheckEndString(input:&dyn Index<RangeFull, Output = char>, stg:i32) {
    if input[stg] == ',' {
        stg += 1;
        CheckBoeingString(input, stg, "".to_string());
    } else if input[stg] != ' ' {
        stg += 1;
        CheckBoeingString(input, stg, "".to_string());
    } else {
        return;
    }
}