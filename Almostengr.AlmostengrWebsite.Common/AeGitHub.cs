using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace Almostengr.AlmostengrWebsite.Common
{
    public static class AeGitHub
    {
        private static void StageAndCommitFiles()
        {
            Process process;

            List<string> commandsToRun = new List<string>();
            commandsToRun.Add("config user.name github-actions");
            commandsToRun.Add("config user.email github-actions@github.com");
            commandsToRun.Add("add .");
            commandsToRun.Add("commit -m \"AutocommitGH\"");
            commandsToRun.Add("push");

            foreach (string singleLine in commandsToRun)
            {
                process = new Process()
                {
                    StartInfo = new ProcessStartInfo()
                    {
                        FileName = "git",
                        Arguments = singleLine,
                        RedirectStandardError = true,
                        RedirectStandardOutput = true,
                        UseShellExecute = false,
                        CreateNoWindow = true,
                    }
                };

                Console.WriteLine("Running command: {0}", singleLine);

                process.Start();
                process.WaitForExit();

                Console.WriteLine(process.StandardError.ReadToEnd().ToString()); // print output from process
            }
        }
    }
}
