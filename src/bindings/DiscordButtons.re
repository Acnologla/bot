module Disbut {
    type t;
    [@bs.new] external messageButton : t => Discord.Button.t = "MessageButton";

}

[@bs.module "discord-buttons"] [@bs.new] external messageButton : unit => Discord.Button.t = "MessageButton";
[@bs.module] external discordButton: Discord.Client.t => unit = "discord-buttons";
