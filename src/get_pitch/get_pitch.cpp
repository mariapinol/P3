/// @file

#include <iostream>
#include <fstream>
#include <string.h>
#include <errno.h>
#include <algorithm>

#include "wavfile_mono.h"
#include "pitch_analyzer.h"

#include "docopt.h"

#define FRAME_LEN   0.030 /* 30 ms. */
#define FRAME_SHIFT 0.015 /* 15 ms. */

using namespace std;
using namespace upc;

static const char USAGE[] = R"(
get_pitch - Pitch Detector 
Usage:
    get_pitch [options] <input-wav> <output-txt> [<pow_th>] [<r1_th>] [<rmax_th>]
    get_pitch (-h | --help)
    get_pitch --version
Options:
    -h, --help  Show this screen
    --version   Show the version of the project
Arguments:
    input-wav   Wave file with the audio signal
    output-txt  Output file: ASCII file with the result of the detection:
                    - One line per frame with the estimated f0
                    - If considered unvoiced, f0 must be set to f0 = 0
)";

int main(int argc, const char *argv[]) {
	/// \TODO 
	///  Modify the program syntax and the call to **docopt()** in order to
	///  add options and arguments to the program.
    std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
        {argv + 1, argv + argc},	// array of arguments, without the program name
        true,    // show help if requested
        "2.0");  // version string

	std::string input_wav = args["<input-wav>"].asString();
	std::string output_txt = args["<output-txt>"].asString();

  float pow_th;
  float r1_th;
  float rmax_th;

  if (argc > 3)
    pow_th = -1.0 * stof(args["<pow_th>"].asString());
  else
    pow_th = -51.5;
  
  if (argc > 4) 
    r1_th = stof(args["<r1_th>"].asString()); 
  else 
    r1_th = 0.6;

  if (argc > 5)
    rmax_th = stof(args["<rmax_th>"].asString());
  else
    rmax_th = 0.25;


  // Read input sound file
  unsigned int rate;
  vector<float> x;
  if (readwav_mono(input_wav, rate, x) != 0) {
    cerr << "Error reading input file " << input_wav << " (" << strerror(errno) << ")\n";
    return -2;
  }

  int n_len = rate * FRAME_LEN;
  int n_shift = rate * FRAME_SHIFT;

  // Define analyzer
  PitchAnalyzer analyzer(n_len, rate, pow_th, r1_th, rmax_th, PitchAnalyzer::HAMMING, 50, 500);

  /// \DONE
  /// Preprocess the input signal in order to ease pitch estimation. For instance,
  /// central-clipping or low pass filtering may be used.
  float cl_threshold = 0.0;
  float pow = 0.0;

  for (unsigned int i = 0; i < x.size(); i++) 
    pow += x[i] * x[i];
  pow /= x.size();

  cl_threshold = 0.8 * pow;

  for (unsigned int i = 0; i < x.size(); i++)
    if (x[i] >= cl_threshold)
      x[i] -= cl_threshold;
    else if (abs(x[i]) < cl_threshold)
      x[i] = 0;
    else 
      x[i] += cl_threshold;

  // Iterate for each frame and save values in f0 vector
  vector<float>::iterator iX;
  vector<float> f0;
  for (iX = x.begin(); iX + n_len < x.end(); iX = iX + n_shift) {
    float f = analyzer(iX, iX + n_len);
    f0.push_back(f);
  }

  /// \DONE
  /// Postprocess the estimation in order to supress errors. For instance, a median filter
  /// or time-warping may be used.

  vector<float>window(3);

  for (unsigned int i = 1; i < f0.size() - 1; ++i) { 
    for (unsigned int p = 0; p < 3; ++p)
      window[p] = f0[i - 1 + p];
    sort(window.begin(), window.end());
    f0[i] = window[1];
  }

  // Write f0 contour into the output file
  ofstream os(output_txt);
  if (!os.good()) {
    cerr << "Error reading output file " << output_txt << " (" << strerror(errno) << ")\n";
    return -3;
  }

  os << 0 << '\n'; //pitch at t=0
  for (iX = f0.begin(); iX != f0.end(); ++iX) 
    os << *iX << '\n';
  os << 0 << '\n';//pitch at t=Dur

  return 0;
}